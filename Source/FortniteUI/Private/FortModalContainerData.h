// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortModalContainerData.generated.h"

USTRUCT(BlueprintType)
struct FFortModalContainerSizeEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortModalContainerSizeEntry")
	float AbsoluteWidth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortModalContainerSizeEntry")
	float TopPercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortModalContainerSizeEntry")
	float MiddlePercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortModalContainerSizeEntry")
	float BottomPercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortModalContainerSizeEntry")
	float VerticalPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortModalContainerSizeEntry")
	float HorizontalPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortModalContainerSizeEntry")
	float ContentPadding;

};

UCLASS()
class UFortModalContainerData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Modal Container Data")
	TArray<FFortModalContainerSizeEntry> Entries;

};

