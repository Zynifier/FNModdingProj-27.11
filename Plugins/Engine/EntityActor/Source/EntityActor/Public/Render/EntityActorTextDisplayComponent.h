// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "EntityActorComponent.h"
#include "EntityActorTextDisplayComponent.generated.h"

UCLASS(meta=(DisplayName="Text Display Component"))
class ENTITYACTOR_API UEntityActorTextDisplayComponent : public UEntityActorComponent
{
	GENERATED_BODY()

public:
	// Get the horizontal alignment 

	UFUNCTION(Category="TextDisplay")
	EHorizTextAligment GetHorizontalAlignment();

	// Get the relative text location

	UFUNCTION(Category="TextDisplay")
	FVector GetRelativeLocation();

	// Get the text value

	UFUNCTION(Category="TextDisplay")
	FText GetText() const;

	// Get the text render color

	UFUNCTION(Category="TextDisplay")
	FColor GetTextRenderColor() const;

	// Change the vertical alignment and signal the primitives to be rebuilt

	UFUNCTION(Category="TextDisplay")
	EVerticalTextAligment GetVerticalAlignment();

	// Get desired world space size of text

	UFUNCTION(Category="TextDisplay")
	float GetWorldSize() const;

	// Change the horizontal alignment and signal the primitives to be rebuilt

	UFUNCTION(Category="TextDisplay")
	void SetHorizontalAlignment(EHorizTextAligment Value);

	// Set the relative text location

	UFUNCTION(Category="TextDisplay")
	void SetRelativeLocation(FVector RelativeLocation);

	// Set the relative text rotation

	UFUNCTION(Category="TextDisplay")
	void SetRelativeRotation(FRotator RelativeRotation);

	// Set the relative text scale

	UFUNCTION(Category="TextDisplay")
	void SetRelativeScale(FVector RelativeScale);

	// Change the text value and signal the primitives to be rebuilt, can be multi line using <br> as line separator

	UFUNCTION(Category="TextDisplay")
	void SetText(FText Text);

	// Change the text render color and signal the primitives to be rebuilt

	UFUNCTION(Category="TextDisplay")
	void SetTextRenderColor(FColor Value);

	// Change the vertical alignment and signal the primitives to be rebuilt

	UFUNCTION(Category="TextDisplay")
	void SetVerticalAlignment(EVerticalTextAligment Value);

	// Change the world size of the text and signal the primitives to be rebuilt

	UFUNCTION(Category="TextDisplay")
	void SetWorldSize(float Value);

private:
	UFUNCTION()
	void OnRep_DisplayText();

	UFUNCTION()
	void OnRep_TextRenderColor();

	UFUNCTION()
	void OnRep_WorldSize();

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_DisplayText, Category="NoCategory")
	FText DisplayText;

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_WorldSize, Category="NoCategory")
	float ShadowVar_WorldSize;

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_TextRenderColor, Category="NoCategory")
	FColor ShadowVar_TextRenderColor;

	UPROPERTY()
	bool bAddedTextRenderComponent;

};

