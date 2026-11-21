// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavAgentSelector.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortAthenaLivingWorldNavigationInvokerComponent.generated.h"

class UFortAthenaLivingWorldManager;

USTRUCT()
struct FortAthenaLivingWorldNavigationInvokerSettingsOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ortAthenaLivingWorldNavigationInvokerSettingsOverride")
	FGameplayTagQuery OverrideTagQuery;

	UPROPERTY(EditAnywhere, Category="ortAthenaLivingWorldNavigationInvokerSettingsOverride")
	FScalableFloat RegistrationDistanceToPlayer;

};

UCLASS(MinimalAPI, ClassGroup=("Navigation"), meta=(BlueprintSpawnableComponent))
class UFortAthenaLivingWorldNavigationInvokerComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldNavigationInvokerComponent", meta=(ClampMin="0.1", UIMin="0.1"))
	FScalableFloat GenerationRadius;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldNavigationInvokerComponent")
	FNavAgentSelector SupportedAgents;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldNavigationInvokerComponent")
	FScalableFloat DistanceToPlayer;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldNavigationInvokerComponent")
	FScalableFloat DistanceToPlayerHysteresis;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldNavigationInvokerComponent")
	FScalableFloat RegistrationDistanceToPlayer;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldNavigationInvokerComponent")
	FScalableFloat RegistrationDistanceToPlayerHysteresis;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldNavigationInvokerComponent")
	TArray<FortAthenaLivingWorldNavigationInvokerSettingsOverride> SettingsOverride;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortAthenaLivingWorldManager> LivingWorldManager;

};

