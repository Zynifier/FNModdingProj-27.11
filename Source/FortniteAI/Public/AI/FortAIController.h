// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavPathObserverInterface.h"
#include "AIController.h"
#include "Math/MathFwd.h"
#include "AI/FortAIEncounterInfoOwnerInterface.h"
#include "AI/FortAITypes.h"
#include "AI/FortAthenaAIControllerInterface.h"
#include "AI/FortAthenaEntitySubsystemInterface.h"
#include "AI/Navigation/FortDoorLinkOpenerInterface.h"
#include "FortTeamActorInterface.h"
#include "FortTeamEnum.h"
#include "FortAIController.generated.h"

class AActor;
class ABuildingSMActor;
class AFortAIController;
class AFortAIPawn;
class AFortPawn;
class UAIGoalComponent;
class UBehaviorTree;
class UFortAIEncounterInfo;
class UFortAthenaAIRuntimeParametersComponent;
class UFortAthenaAIRuntimeParameters_AffiliationBase;
class UFortControllerComponent;
class UFortGameStateComponent_AffiliationManager;
class UFortPathFollowingComponent;
class UObject;
enum class EFortressAIType : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAIControllerComponentAttached, AFortAIController*, OwnerController, UFortControllerComponent*, AttachedComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAIControllerNewGoalActor, AActor*, NewActor, AActor*, OldActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPawnKilled, const AFortAIController*, AIController, AFortPawn*, KilledPawn);

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortAIController : public AAIController, public IFortTeamActorInterface, public INavPathObserverInterface, public IFortAIEncounterInfoOwnerInterface, public IFortAthenaAIControllerInterface, public IFortDoorLinkOpenerInterface, public IFortAthenaEntitySubsystemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void ClearAllFocalPoints();

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API bool CreateBuildingActor(TSubclassOf<ABuildingSMActor> BuildingClass, FVector BuildLoc, FRotator BuildRot, bool bMirrored);

	UFUNCTION(BlueprintPure, Category="Encounter")
	FORTNITEAI_API virtual UFortAIEncounterInfo* GetEncounterInfo() const;

	UFUNCTION(BlueprintPure, Category="AI")
	FORTNITEAI_API AActor* GetGoalActor() const;

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API virtual void IgnoreProximityForDuration(float DurationToIgnore);

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API bool IsAllowedToSleep();

	UFUNCTION(BlueprintPure, Category="AI")
	FORTNITEAI_API static bool IsIgnoringProximity(AFortAIController* FortAIController);

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void LockBehaviorResource();

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void LockMovementResource();

	UFUNCTION()
	FORTNITEAI_API void OnActorGoalDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	FORTNITEAI_API void OnBuildingActorGoalDestroyed();

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void SetAlwaysGameplayRelevant(bool bInAlwaysGameplayRelevant);

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void SetFullPeripheralVision(bool bNewFullPeripheralVision);

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void SetGoalActor(AActor* InActor, bool bLocationAlwaysKnown = false);

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void SetIsSleeping(bool bNewSleepStatus);

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void SetPawnAIType(EFortressAIType NewAIType, AActor* SpawnSpot = nullptr);

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void SetTeam(EFortTeam::Type InTeam);

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void SetTeamInt(uint8 InTeam);

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void SetupCustomVIM(UClass* VIM);

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void UnlockBehaviorResource();

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void UnlockMovementResource();

	UFUNCTION(BlueprintCallable, Category="AI")
	FORTNITEAI_API void WakeUp();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	uint8 bUsingNavMesh : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Navigation")
	uint8 bAlwaysNotifyBumpWall : 1;

	UPROPERTY(Config)
	uint8 bInstantRotation : 1;

	UPROPERTY(BlueprintReadOnly, Export, Category="AI", meta=(EditInline="true"))
	TObjectPtr<UFortPathFollowingComponent> FortPathFollowingComp;

	UPROPERTY(Config)
	float GoalInfoUpdateRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Pawn")
	TObjectPtr<AFortAIPawn> MyFortPawn;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Navigation")
	uint8 bTurnTransitionsEnabled : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	uint8 bIgnoreAllActorsThatAreNotPawnsOrBuildings : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Navigation")
	uint8 bAllowHotspotAbilityLooping : 1;

	UPROPERTY(BlueprintReadOnly, Category="AI")
	FAIHotSpotUseInfo CurrentHotSpot;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaAIRuntimeParametersComponent> CachedAIRuntimeParametersComponent;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_AffiliationBase> CachedAffiliationRuntimeParameters;

	UPROPERTY()
	TObjectPtr<AActor> GoalActor;

	UPROPERTY(Config)
	float GoalVisibilityPersistanceTime;

	UPROPERTY(BlueprintAssignable, Category="Team")
	FOnTeamIndexChangedDelegate OnTeamSetDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnAIControllerComponentAttached OnControllerComponentAttachedEvent;

	UPROPERTY(BlueprintReadOnly, Export, Category="GoalSelection", meta=(EditInline="true"))
	TObjectPtr<UAIGoalComponent> AIGoalComponent;

	UPROPERTY(BlueprintAssignable)
	FOnAIControllerNewGoalActor OnControllerNewGoalActorEvent;

	UPROPERTY(BlueprintAssignable)
	FOnPawnKilled OnPawnKilledEvent;

	UPROPERTY(Transient)
	TObjectPtr<UBehaviorTree> BTAssetToRunOnPawnAISpawned;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_AffiliationManager> CachedAffiliationManager;

};

