// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "FortGameplayTagActor.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class AFortGameplayTagActor : public AActor, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UPROPERTY(EditDefaultsOnly, Category="GameplayActor")
	FGameplayTagContainer GameplayTags;

};

