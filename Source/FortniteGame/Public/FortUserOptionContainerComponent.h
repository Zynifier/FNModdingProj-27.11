// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortPropertyOverrideData.h"
#include "FortUserOptionValues.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortUserOptionContainerComponent.generated.h"

class UFortUserDefinedBehaviorSetNode;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Custom"), SparseClassDataType=UserOptionDefinitionContainer, meta=(BlueprintSpawnableComponent))
class UFortUserOptionContainerComponent : public UActorComponent, public ILevelSaveSpawnable, public IUserOptionValuesInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="UserOptions", meta=(DisplayName="Handle User Options Changed"))
	FORTNITEGAME_API void K2_HandleUserOptionsChanged(const TArray<FName>& ChangedPropertyNames);

	UFUNCTION(BlueprintImplementableEvent, Category="UserOptions", meta=(DisplayName="Handle User Options Loaded"))
	FORTNITEGAME_API void K2_HandleUserOptionsLoaded();

	UPROPERTY(SaveGame, Replicated)
	FPropertyOverrideData UserOptionData;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Behavior")
	TArray<TObjectPtr<UFortUserDefinedBehaviorSetNode>> BehaviorSetNodes;

};

