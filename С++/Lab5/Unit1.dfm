object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 514
  ClientWidth = 688
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 280
    Top = 8
    Width = 149
    Height = 23
    Caption = 'Work with Queue'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 272
    Top = 120
    Width = 92
    Height = 19
    Caption = 'Only 1 repeat'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object ListBox1: TListBox
    Left = 8
    Top = 96
    Width = 233
    Height = 273
    TabOrder = 0
  end
  object Button1: TButton
    Left = 272
    Top = 175
    Width = 97
    Height = 41
    Caption = 'Recycle'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 80
    Top = 48
    Width = 97
    Height = 42
    Caption = 'Randomize'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 560
    Top = 400
    Width = 97
    Height = 49
    Caption = 'Clear Queue'
    TabOrder = 3
    OnClick = Button3Click
  end
  object ListBox2: TListBox
    Left = 424
    Top = 96
    Width = 233
    Height = 273
    TabOrder = 4
  end
  object Button4: TButton
    Left = 8
    Top = 408
    Width = 81
    Height = 33
    Caption = 'Delete'
    TabOrder = 5
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 112
    Top = 408
    Width = 81
    Height = 35
    Caption = 'Add'
    TabOrder = 6
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 216
    Top = 407
    Width = 81
    Height = 35
    Caption = 'Get Size'
    TabOrder = 7
    OnClick = Button6Click
  end
  object Edit1: TEdit
    Left = 112
    Top = 452
    Width = 81
    Height = 24
    TabOrder = 8
  end
  object Panel1: TPanel
    Left = 216
    Top = 448
    Width = 73
    Height = 33
    TabOrder = 9
  end
  object Button7: TButton
    Left = 424
    Top = 400
    Width = 97
    Height = 49
    Caption = 'Clear field'
    TabOrder = 10
    OnClick = Button7Click
  end
end
