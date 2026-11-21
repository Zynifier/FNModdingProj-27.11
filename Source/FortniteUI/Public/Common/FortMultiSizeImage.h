// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Math/Color.h"
#include "FortBrushSize.h"
#include "FortMultiSize.h"
#include "FortMultiSizeImage.generated.h"

UCLASS(BlueprintType)
class UFortMultiSizeImage : public UWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Multi-Size Image")
	void SetBrushSize(EFortBrushSize::Type BrushSize);

	UFUNCTION(BlueprintCallable, Category="Multi-Size Image")
	void SetColorAndOpacity(const FLinearColor& Color);

	UFUNCTION(BlueprintCallable, Category="Multi-Size Image")
	void SetMultiSizeBrush(const FFortMultiSizeBrush& MultiSizeBrush);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Multi-Size Image")
	FFortMultiSizeBrush MultiSizeBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Multi-Size Image")
	TEnumAsByte<EFortBrushSize::Type> BrushSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Multi-Size Image")
	FLinearColor ColorAndOpacity;

};

