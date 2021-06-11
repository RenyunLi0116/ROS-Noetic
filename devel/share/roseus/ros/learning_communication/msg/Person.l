;; Auto-generated. Do not edit!


(when (boundp 'learning_communication::Person)
  (if (not (find-package "LEARNING_COMMUNICATION"))
    (make-package "LEARNING_COMMUNICATION"))
  (shadow 'Person (find-package "LEARNING_COMMUNICATION")))
(unless (find-package "LEARNING_COMMUNICATION::PERSON")
  (make-package "LEARNING_COMMUNICATION::PERSON"))

(in-package "ROS")
;;//! \htmlinclude Person.msg.html


(defclass learning_communication::Person
  :super ros::object
  :slots ())

(defmethod learning_communication::Person
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(setf (get learning_communication::Person :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get learning_communication::Person :datatype-) "learning_communication/Person")
(setf (get learning_communication::Person :definition-)
      "
")



(provide :learning_communication/Person "d41d8cd98f00b204e9800998ecf8427e")


