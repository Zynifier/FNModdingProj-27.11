// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Athena/Modifiers/FortAthenaMutator_EQSProviderInterface.h"
#include "FortAthenaMutator_DeimosSurvival.generated.h"

class AActor;
class ABuildingActor;
class AController;
class UEnvQuery;
class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FFortAthenaMutator_SurvivalObjectiveData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_SurvivalObjectiveData", meta=(AllowPrivateAccess="true"))
	TSubclassOf<ABuildingActor> BuildingActorObjectiveClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_SurvivalObjectiveData", meta=(AllowPrivateAccess="true"))
	FScalableFloat SpawnDistanceFromGround;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaMutator_SurvivalObjectiveData", meta=(AllowPrivateAccess="true"))
	int32 ActivationSafezoneIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaMutator_SurvivalObjectiveData", meta=(AllowPrivateAccess="true"))
	uint8 bEndMatchOnDestroy : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objective Location", meta=(AllowPrivateAccess="true"))
	uint8 bSpawnOnPOI : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objective Location", meta=(AllowPrivateAccess="true"))
	bool bClearAreaOnSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objective Location", meta=(AllowPrivateAccess="true"))
	float ClearAreaRadiusOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objective Location", meta=(AllowPrivateAccess="true"))
	float ClearAreaHalfHeightOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Special Actor", meta=(AllowPrivateAccess="true"))
	uint8 bIsSpecialActor : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objective Location", meta=(AllowPrivateAccess="true", EditCondition="bSpawnOnPOI"))
	FGameplayTagQuery POIFilterQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objective Location", meta=(AllowPrivateAccess="true", ClampMin="1", EditCondition="bSpawnOnPOI", UIMin="1"))
	int32 RandomizedPOICount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objective Location", meta=(AllowPrivateAccess="true", EditCondition="bSpawnOnPOI"))
	TArray<int32> ExtraSafezoneIndexes;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingActor> SpawnedBuildingActorObjective;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Special Actor", meta=(AllowPrivateAccess="true", EditCondition="bIsSpecialActor"))
	FGameplayTag SpecialActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Special Actor", meta=(AllowPrivateAccess="true", EditCondition="bIsSpecialActor"))
	FSlateBrush SpecialActorMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Special Actor", meta=(AllowPrivateAccess="true", EditCondition="bIsSpecialActor"))
	FVector2D SpecialActorMinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Special Actor", meta=(AllowPrivateAccess="true", EditCondition="bIsSpecialActor"))
	FSlateBrush SpecialActorCompassIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Special Actor", meta=(AllowPrivateAccess="true", EditCondition="bIsSpecialActor"))
	FVector2D SpecialActorCompassIconScale;

	UPROPERTY(Transient)
	FName SpecialActorID;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_DeimosSurvival : public AFortAthenaMutator, public IFortAthenaMutator_EQSProviderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnBuildingActorDestroyed(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnPlaylistDataLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContainerTag);

	UFUNCTION()
	void OnSafezoneChanged(const FFortSafeZonePhaseUpdatedEvent& Event);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DeimosMessages")
	FAthenaGameMessageData GameMsg_Intro;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DeimosMessages")
	FAthenaGameMessageData GameMsg_CompleteObjective;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DeimosMessages")
	FAthenaGameMessageData GameMsg_DownTime;

private:
	UPROPERTY(EditDefaultsOnly, Category="Base Query", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UEnvQuery> AdjustSafezoneCentersQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objectives", meta=(AllowPrivateAccess="true"))
	TArray<FFortAthenaMutator_SurvivalObjectiveData> ObjectivesData;

};

