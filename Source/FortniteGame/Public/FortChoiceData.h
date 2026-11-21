// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortChoiceData.generated.h"

USTRUCT(BlueprintType)
struct FChoiceDataEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MenuItem")
	FText ButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MenuItem")
	FText ButtonDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MenuItem")
	FText ConfirmText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MenuItem")
	bool bEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MenuItem")
	bool bRequireConfirmation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MenuItem")
	bool bCloseAfterSelection;

};

USTRUCT(BlueprintType)
struct FChoiceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MenuItem")
	int32 MenuIdentifier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MenuItem")
	bool bShowCloseButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MenuItem")
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MenuItem")
	TArray<FChoiceDataEntry> Items;

};

