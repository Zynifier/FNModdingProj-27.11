// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FieldNotification/WidgetEventField.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Layout/Margin.h"
#include "Types/MVVMEventField.h"
#include "CreativeModalDialogConversionFunction.generated.h"

enum class ECreativeModalDialogAlignmentOption : uint8;
enum class ECreativeModalDialogViewmodelResponse : uint8;

UCLASS()
class UCreativeModalDialogAllowedConversionFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static ECreativeModalDialogViewmodelResponse GetResponseButton1(FWidgetEventField Field);

	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static ECreativeModalDialogViewmodelResponse GetResponseButton2(FWidgetEventField Field);

	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static ECreativeModalDialogViewmodelResponse GetResponseButton3(FWidgetEventField Field);

	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static ECreativeModalDialogViewmodelResponse GetResponseButton4(FWidgetEventField Field);

	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static ECreativeModalDialogViewmodelResponse GetResponseButton5(FWidgetEventField Field);

	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static ECreativeModalDialogViewmodelResponse GetResponseButton6(FWidgetEventField Field);

	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static ECreativeModalDialogViewmodelResponse GetResponseNone(FWidgetEventField Field);

};

UCLASS()
class UCreativeModalDialogConversionFunction : public UCreativeModalDialogAllowedConversionFunction
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static ECreativeModalDialogViewmodelResponse AssignCreativeModalDialogViewmodelResponse(FMVVMEventField Field, ECreativeModalDialogViewmodelResponse Response);

	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static int32 GetColumnIndexForButtonFromContentAlignment(const ECreativeModalDialogAlignmentOption AlignmentOption, const int32 ButtonIndex, const int32 WideMaxColumns, const int32 TallMaxColumns, const int32 DefaultMaxColumns);

	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static float GetFloatingValueFromContentAlignment(const ECreativeModalDialogAlignmentOption AlignmentOption, const float TallValue, const float WideValue, const float CenteredFullValue, const float DefaultValue);

	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static FMargin GetMarginFromContentAlignment(const ECreativeModalDialogAlignmentOption AlignmentOption, const float TallMarginAmount, const float WideMarginAmount, const float CenteredFullMarginAmount, const float DefaultMarginAmount);

	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static int32 GetRowIndexForButtonFromContentAlignment(const ECreativeModalDialogAlignmentOption AlignmentOption, const int32 ButtonIndex, const int32 WideMaxColumns, const int32 TallMaxColumns, const int32 DefaultMaxColumns);

	UFUNCTION(BlueprintPure, Category="Creative|ModalDialog|ConversionFunction")
	static ECreativeModalDialogViewmodelResponse TranslateResponse(FWidgetEventField Field, ECreativeModalDialogViewmodelResponse Response);

};

