class Question:

    def __init__(self,q_text,q_answer):
        self.text = q_text
        self.answer = q_answer

naw_q = Question("2+3=5", "True")
print(naw_q.text)
