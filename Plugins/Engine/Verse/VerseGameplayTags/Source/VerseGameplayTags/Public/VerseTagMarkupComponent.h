// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VerseGameplayTagAssetInterface.h"
#include "VerseGameplayTagContainer.h"
#include "VerseTagMarkupComponent.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class VERSEGAMEPLAYTAGS_API UVerseTagMarkupComponent : public UActorComponent, public IVerseGameplayTagAssetInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="GameplayTags", meta=(DisplayName="Tags", ShowOnlyInnerProperties))
	FVerseGameplayTagContainer InternalTags;

};

