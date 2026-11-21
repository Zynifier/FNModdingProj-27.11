// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "XpEverywhereUIComponent.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UXpEverywhereUIComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="XpEverywhereUIComponent")
	FGameplayTagContainer XpEverywhereHiddenElementTags;

};

