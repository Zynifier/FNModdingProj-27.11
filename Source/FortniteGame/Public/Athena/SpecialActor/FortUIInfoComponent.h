// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortUIInfoComponent.generated.h"

class UTexture2D;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortUIInfoComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Text")
	FText LabelText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Text")
	FText DescriptionText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Image")
	TSoftObjectPtr<UTexture2D> TextureSoftPointer;

};

