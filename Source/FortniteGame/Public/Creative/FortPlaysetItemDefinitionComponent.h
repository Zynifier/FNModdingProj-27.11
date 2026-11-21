// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/FortPlaysetSettings.h"
#include "FortPlaysetItemDefinitionComponent.generated.h"

class UFortPlaysetItemDefinition;

UCLASS(HideCategories=("Activation", "AssetUserData", "Collision", "ComponentTick", "ComponentReplication", "Cooking", "Tags", "Variable"), ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent, DisplayName="Creative Playset"))
class UFortPlaysetItemDefinitionComponent : public UActorComponent
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Creative Playset", meta=(ShowOnlyInnerProperties))
	FPlaysetSettings PlaysetSettings;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Creative Playset")
	TSoftObjectPtr<UFortPlaysetItemDefinition> Playset;
#endif

};

