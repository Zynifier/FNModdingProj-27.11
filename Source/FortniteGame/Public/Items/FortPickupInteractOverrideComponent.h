// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "FortPickupInteractOverrideComponent.generated.h"

class UFortInteractContextInfoWidget;

UCLASS(MinimalAPI, HideCategories=("ComponentReplication", "Activation", "Cooking", "AssetUserData", "Collision", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPickupInteractOverrideComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	FORTNITEGAME_API UFortPickupInteractOverrideComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API int32 GetPriority() const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortPickupInteractOverrideComponent")
	int32 Priority;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPickupInteractOverrideComponent")
	TSubclassOf<UFortInteractContextInfoWidget> ContextOverrideWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPickupInteractOverrideComponent")
	TSubclassOf<UFortInteractContextInfoWidget> SecondContextOverrideWidget;

	UPROPERTY(BlueprintReadOnly, Category="FortPickupInteractOverrideComponent")
	bool bContextOverrideWidgetApplied;

};

