// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "BattleBusCosmeticInstanceBase.generated.h"

class UAthenaBattleBusItemDefinition;

UCLASS(BlueprintType, Blueprintable)
class ABattleBusCosmeticInstanceBase : public AActor, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="BattleBusCosmeticInstanceBase")
	TObjectPtr<UAthenaBattleBusItemDefinition> ActiveSkin;

};

