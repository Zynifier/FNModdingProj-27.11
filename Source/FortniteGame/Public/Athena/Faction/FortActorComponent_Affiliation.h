// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/Faction/FortFactionInfo.h"
#include "Athena/Faction/FortFactionMapping.h"
#include "FortActorComponent_Affiliation.generated.h"

class AActor;
class AController;
class AFortAthenaAIBotController;
class APawn;
class UAIPerceptionComponent;
class UFortActorComponent_Affiliation;
class UFortGameStateComponent_AffiliationManager;
class UPrimitiveComponent;
enum class EAlertLevel : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRelationsUpdate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSpecificRelationAdded, AActor*, TowardsActor, const TEnumAsByte<EFortFactionAttitude::Type>, NewAttitude);

USTRUCT()
struct FFortAffiliationComponentSpecificRelations
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FFortAffiliationActorIdentifierList Identifiers;

	UPROPERTY(Transient, NotReplicated, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortActorComponent_Affiliation>> Components;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortActorComponent_Affiliation : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetCanBeDamagedByNullInstigator(const bool bInCanBeDamagedByNullInstigator);

private:
	UFUNCTION()
	void OnBotControllerAlertLevelChanged(AFortAthenaAIBotController* BotController, EAlertLevel OldAlertLevel, EAlertLevel NewAlertLevel);

	UFUNCTION()
	void OnOwnerPawnDamaged(AActor* DamageOnOwnerPawnDamageddActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnOwnerPawnPossessed(APawn* Pawn);

	UFUNCTION()
	void OnOwnerPawnUnpossessed(APawn* Pawn);

	UFUNCTION()
	void OnOwnerTeamIndexChanged();

	UFUNCTION()
	void OnRep_CurrentFactions();

	UFUNCTION()
	void OnRep_SpecificRelations();

	UFUNCTION()
	void UpdatePerception();

	UPROPERTY(Transient, Replicated)
	uint8 bHasSpecificRelations : 1;

	UPROPERTY(Transient)
	bool bHasPerceptionUpdateRequest;

	UPROPERTY(Transient)
	bool bIsInGameParticipantFaction;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Faction", meta=(Categories="Athena.Faction"))
	FGameplayTagContainer DefaultFactionTags;

	UPROPERTY(Transient)
	uint8 bIsRegisteredToAffiliationSystem : 1;

	UPROPERTY(Transient)
	float ResetSpecificRelationUnawareDelay;

	UPROPERTY(Transient)
	float ResetSpecificRelationNoDamageDelay;

	UPROPERTY(Transient, Replicated)
	uint32 AffiliationUID;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CurrentFactions)
	FGameplayTagContainer CurrentFactions;

	UPROPERTY(Transient)
	FGameplayTagContainer CurrentBlockResetRelationTags;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_SpecificRelations, meta=(ArraySizeEnum="/Script/FortniteGame.EFortFactionAttitude"))
	FFortAffiliationComponentSpecificRelations SpecificRelations[3];

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortGameStateComponent_AffiliationManager> CachedAffiliationManager;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAIPerceptionComponent> CachedAIPerceptionComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaAIBotController> CachedBotController;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortActorComponent_Affiliation> GameplayOwnerAffiliationComponent;

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UFortActorComponent_Affiliation>> GameplayOwnedAffiliationComponents;

	UPROPERTY(EditDefaultsOnly, Category="FortActorComponent_Affiliation")
	bool bCanBeDamagedByNullInstigator;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnSpecificRelationAdded OnSpecificRelationAddedDelegate;

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="On Relations Update (Client)", AllowPrivateAccess="true"))
	FOnRelationsUpdate OnRelationsUpdateDelegate;

};

