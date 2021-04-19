import cv2             #Libreria OpenCV
import mediapipe as mp #Libreria de mediapipe
from pyfirmata import Arduino, SERVO #Libreria Firmata

board = Arduino('com4') # Declarando puerto de arduino DUE
board.digital[2].mode = SERVO   #Pulgar
board.digital[3].mode = SERVO   #Indice
board.digital[4].mode = SERVO   #Mediano
board.digital[5].mode = SERVO   #Anular
board.digital[6].mode = SERVO   #Meñique
board.digital[7].mode = SERVO   #Muñeca
board.digital[8].mode = SERVO   #Pulgar Horizontal
board.digital[9].mode = SERVO   #Indice Horizontal
board.digital[10].mode = SERVO  #Mediano Horizontal
board.digital[11].mode = SERVO  #Anular Horizontal
board.digital[12].mode = SERVO  #Meñique Horizontal
board.digital[13].mode = SERVO  #Muñeca Horizontal

# Posiciones iniciales de la mano robótica
board.digital[2].write(179)  #Pulgar
board.digital[3].write(179)  #Indice
board.digital[4].write(179)  #Medio
board.digital[5].write(1)    #Anular
board.digital[6].write(1)    #Meñique
board.digital[7].write(120)  #Muñeca
board.digital[8].write(60)   #Pulgar Horizontal
board.digital[9].write(48)   #Indice Horizontal
board.digital[10].write(75)  #Medio Horizontal
board.digital[11].write(66)  #Anular Horizontal
board.digital[12].write(67)  #Meñique Horizontal
board.digital[13].write(130) #Muñeca Horizontal

# Dimensiones de la pantalla
screen_width = 1280
screen_height = 1024

# Variables para las herramientas del modelo
# de la mano de mediapipe
mp_drawing = mp.solutions.drawing_utils
mp_hands = mp.solutions.hands

# Parametros para la salida de video en la pantalla
hands = mp_hands.Hands(min_detection_confidence=0.7,
                       min_tracking_confidence=0.9,
                       max_num_hands=1)
cap = cv2.VideoCapture(2)  # Camara Web
cap.set(3, screen_width)
cap.set(4, screen_height)
cap_width = int(cap.get(3))
cap_height = int(cap.get(4))

# Variables para operaciones de detección de mano
no = 1000           #numero de multiplicacion
new_min = int(1)    #valor minimo de servomotores
new_max = int(179)  #valor maximo de servomotores

while cap.isOpened():
    success, image = cap.read()
    if not success:
        print("No se detecta cámara")
        continue
    # Voltea la imagen inversamente para el reflejo en la pantalla
    # y convierte la imagen BGR a RGB
    image = cv2.cvtColor(cv2.flip(image, 1), cv2.COLOR_BGR2RGB)
    results = hands.process(image)
    image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
    if results.multi_hand_landmarks:

        # Posiciones de los dedos en el eje X y eje Y
        pulgarx = int(no * (results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.THUMB_TIP].x))
        pulgary = int(no * (results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.THUMB_TIP].y))
        indicex = int(no * (results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP].x))
        indicey = int(no * (results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP].y))
        mediox = int(no * (results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.MIDDLE_FINGER_TIP].x))
        medioy = int(no * (results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.MIDDLE_FINGER_TIP].y))
        anularx = int(no * (results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.RING_FINGER_TIP].x))
        anulary = int(no * (results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.RING_FINGER_TIP].y))
        meñiquex = int(no * (results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.PINKY_TIP].x))
        meñiquey = int(no * (results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.PINKY_TIP].y))
        muñecax = int(no * (results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.PINKY_MCP].x))
        muñecay = int(no * (results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.WRIST].y))

        # Movimiento de muñeca en vertical
        Ny_min = 870
        Ny_max = 730
        Ny = int(((muñecay - Ny_min) / (Ny_max - Ny_min)) * (new_max - new_min) + new_min)
        if Ny >= new_min and Ny <= new_max and muñecax >= 585 and muñecax <= 700:
            board.digital[7].write(Ny)

        # Movimiento de muñeca en horizontal
        Nx_min = 700
        Nx_max = 595
        Nx = int(((muñecax - Nx_min) / (Nx_max - Nx_min)) * (178 - 3) + 3)
        if Nx >= 3 and Nx <= 178:
            board.digital[13].write(Nx)

        # Condicion para efectuar movimientos de la mano robotica
        if muñecay >= 750 and muñecay <= 800 and muñecax >= 485 and muñecax <= 735:

            # Pulgar
            Py_min = int(580)
            Py_max = int(410)
            Py = int(((pulgarx - Py_min) / (Py_max - Py_min)) * (new_max - new_min) + new_min)
            if Py >= new_min and Py <= new_max:
                board.digital[2].write(Py)

            # Indice
            Iy_min = int(600)
            Iy_max = int(300)
            Iy = int(((indicey - Iy_min) / (Iy_max - Iy_min)) * (new_max - new_min) + new_min)
            if Iy >= new_min and Iy <= new_max:
                board.digital[3].write(Iy)

            # Medio
            My_min = int(600)
            My_max = int(240)
            My = int(((medioy - My_min) / (My_max - My_min)) * (new_max - 1) + 1)
            if My >= 1 and My <= new_max:
                board.digital[4].write(My)

            # Anular
            Ay_min = int(280)
            Ay_max = int(620)
            Ay = int(((anulary - Ay_min) / (Ay_max - Ay_min)) * (new_max - new_min) + new_min)
            if Ay >= new_min and Ay <= new_max:
                board.digital[5].write(Ay)

            # Meñique
            Qy_min = int(385)
            Qy_max = int(620)
            Qy = int(((meñiquey - Qy_min) / (Qy_max - Qy_min)) * (new_max - new_min) + new_min)
            if Qy >= new_min and Qy <= new_max:
                board.digital[6].write(Qy)

            # Pulgar Horizontal
            Px_min = int(480)
            Px_max = int(580)
            Px = int(((pulgary - Px_min) / (Px_max - Px_min)) * (155 - 1) + 1)
            if Px >= 1 and Px <= 155:
                board.digital[8].write(Px)

            # Indice Horizontal
            Ix_min = int(460)
            Ix_max = int(560)
            Ix = int(((indicex - Ix_min) / (Ix_max - Ix_min)) * (110 - 60) + 60)
            if Ix >= 60 and Ix <= 110:
                board.digital[9].write(Ix)

            # Medio Horizontal
            Mx_min = int(500)
            Mx_max = int(650)
            Mx = int(((mediox - Mx_min) / (Mx_max - Mx_min)) * (152 - 77) + 77)
            if Mx >= 77 and Mx <= 152:
                board.digital[10].write(Mx)

            # Anular Horizontal
            Ax_min = int(560)
            Ax_max = int(645)
            Ax = int(((anularx - Ax_min) / (Ax_max - Ax_min)) * (90 - 45) + 45)
            if Ax >= 45 and Ax <= 90:
                board.digital[11].write(Ax)

            # Meñique Horizontal
            Qx_min = int(575)
            Qx_max = int(700)
            Qx = int(((meñiquex - Qx_min) / (Qx_max - Qx_min)) * (86 - 20) + 20)
            if Qx >= 20 and Qx <= 86:
                board.digital[12].write(Qx)

        for hand_landmarks in results.multi_hand_landmarks: #Dibujos de los puntos de referencia de la mano en la pantal
         mp_drawing.draw_landmarks(image, hand_landmarks, mp_hands.HAND_CONNECTIONS)

    # Configuración para crear un rectángulo rojo en la pantalla
    cv2.rectangle(image, (500, 150), (900, 580), color=(0, 0, 255), thickness=4)
    cv2.imshow('Detección de gestos de la mano', image)
    if cv2.waitKey(1) & 0xFF == 27:
        break

hands.close()
cap.release()