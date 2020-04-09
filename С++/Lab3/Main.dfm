object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Bus Schedule'
  ClientHeight = 524
  ClientWidth = 1028
  Color = clLime
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 8
    Top = 32
    Width = 60
    Height = 19
    Caption = 'Number'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 78
    Width = 34
    Height = 19
    Caption = 'Type'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 125
    Width = 41
    Height = 19
    Caption = 'Point'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 167
    Width = 57
    Height = 19
    Caption = 'Time ot'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 8
    Top = 224
    Width = 59
    Height = 19
    Caption = 'Time pr'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 8
    Top = 408
    Width = 38
    Height = 19
    Caption = 'Time'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 256
    Top = 408
    Width = 41
    Height = 19
    Caption = 'Point'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 252
    Top = 264
    Width = 135
    Height = 19
    Caption = 'Number in the list'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label9: TLabel
    Left = 648
    Top = 264
    Width = 135
    Height = 19
    Caption = 'Number in the list'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label10: TLabel
    Left = 381
    Top = 6
    Width = 111
    Height = 19
    Caption = 'At the Bus stop'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label11: TLabel
    Left = 776
    Top = 8
    Width = 82
    Height = 19
    Caption = 'On the way'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label12: TLabel
    Left = 192
    Top = 363
    Width = 50
    Height = 19
    Caption = 'Search'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 104
    Top = 31
    Width = 121
    Height = 24
    MaxLength = 2
    NumbersOnly = True
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 104
    Top = 77
    Width = 121
    Height = 24
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 104
    Top = 124
    Width = 121
    Height = 24
    TabOrder = 2
  end
  object Button1: TButton
    Left = 64
    Top = 280
    Width = 89
    Height = 33
    Caption = 'Add'
    TabOrder = 3
    OnClick = Button1Click
  end
  object RichEdit1: TRichEdit
    Left = 256
    Top = 31
    Width = 353
    Height = 212
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 4
    Zoom = 100
  end
  object Button2: TButton
    Left = 531
    Top = 312
    Width = 177
    Height = 70
    Caption = 'Show'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 30
    Top = 456
    Width = 89
    Height = 33
    Caption = 'Before Time'
    TabOrder = 6
    OnClick = Button3Click
  end
  object Edit6: TEdit
    Left = 64
    Top = 407
    Width = 121
    Height = 24
    NumbersOnly = True
    TabOrder = 7
  end
  object Button4: TButton
    Left = 288
    Top = 456
    Width = 89
    Height = 33
    Caption = 'To Point'
    TabOrder = 8
    OnClick = Button4Click
  end
  object Edit7: TEdit
    Left = 317
    Top = 407
    Width = 121
    Height = 24
    TabOrder = 9
  end
  object RichEdit2: TRichEdit
    Left = 648
    Top = 31
    Width = 353
    Height = 212
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      '')
    ParentFont = False
    ReadOnly = True
    TabOrder = 10
    Zoom = 100
  end
  object Button5: TButton
    Left = 520
    Top = 259
    Width = 89
    Height = 33
    Caption = 'Out'
    TabOrder = 11
    OnClick = Button5Click
  end
  object Edit8: TEdit
    Left = 393
    Top = 263
    Width = 121
    Height = 24
    NumbersOnly = True
    TabOrder = 12
  end
  object Button6: TButton
    Left = 912
    Top = 259
    Width = 89
    Height = 33
    Caption = 'In'
    TabOrder = 13
    OnClick = Button6Click
  end
  object Edit9: TEdit
    Left = 789
    Top = 263
    Width = 121
    Height = 24
    NumbersOnly = True
    TabOrder = 14
  end
  object Button7: TButton
    Left = 896
    Top = 452
    Width = 105
    Height = 41
    Caption = 'Exit'
    TabOrder = 15
    OnClick = Button7Click
  end
  object Edit4: TMaskEdit
    Left = 104
    Top = 166
    Width = 39
    Height = 24
    EditMask = '!99:99;1;_'
    MaxLength = 5
    ParentShowHint = False
    ShowHint = False
    TabOrder = 16
    Text = '  :  '
  end
  object Edit5: TMaskEdit
    Left = 104
    Top = 219
    Width = 39
    Height = 24
    EditMask = '!90:00;1;_'
    MaxLength = 5
    ParentShowHint = False
    ShowHint = False
    TabOrder = 17
    Text = '  :  '
  end
end
