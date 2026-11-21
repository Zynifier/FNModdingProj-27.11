// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Building/BuildingProp.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
#include "FortConstructorBASE.generated.h"

class AActor;
class ABuildingSMActor;
class AController;
class AFortPawn;
class UAbilitySystemComponent;
class UBuildingEditModeMetadata;
class UGameplayEffect;
class UPrimitiveComponent;
class UStaticMesh;
class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FBASEGameplayEffect
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BASE")
	TSubclassOf<UGameplayEffect> Effect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BASE")
	int32 LevelOverride;

};

USTRUCT(BlueprintType)
struct FFortConstructorBASEActorClassData : public FBuildingPropActorClassData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FPatternBASEEffect
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="BASE")
	TObjectPtr<UBuildingEditModeMetadata> Pattern;

	UPROPERTY(EditDefaultsOnly, Category="BASE")
	TObjectPtr<UStaticMesh> Mesh;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=FortConstructorBASEActorClassData)
class AFortConstructorBASE : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="BASE", meta=(DeprecatedFunction, DeprecationMessage="This should no longer need to be used."))
	TArray<ABuildingSMActor*> GetBuildingActorsInBase();

	UFUNCTION(BlueprintCallable, Category="BASE")
	void GetResourceAmountsBasedOnUpgradeTier(int32 TierOneUpgradeAmount, int32 TierTwoUpgradeAmount, int32 TierThreeUpgradeAmount, int32& WoodResult, int32& StoneResult, int32& MetalResult);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="BASE")
	void OnPawnAddedToBase(AFortPawn* Pawn);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="BASE")
	void OnPawnRemovedFromBase(AFortPawn* Pawn);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="BASE")
	void OnPlaced(UAbilitySystemComponent* InstigatorAbilitySystemComponent);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="BASE")
	void StartBuildingActorVisuals(ABuildingSMActor* BuildingActor, UStaticMeshComponent* EffectMeshComp);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="BASE")
	void StopBuildingActorVisuals(ABuildingSMActor* BuildingActor, UStaticMeshComponent* EffectMeshComp);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BASE")
	TArray<FBASEGameplayEffect> BASEBuildingApplicationEffects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BASE")
	TArray<FBASEGameplayEffect> BASEFriendlyApplicationEffects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BASE")
	TArray<FBASEGameplayEffect> BASEFriendlyApplicationTrapEffects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BASE")
	TArray<FBASEGameplayEffect> BASEEnemyApplicationEffects;

	UPROPERTY(EditDefaultsOnly, Category="BASE")
	FGameplayTag InBASETag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BASE")
	int32 NodesToAffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BASE")
	int32 BASELevel;

	UPROPERTY(EditDefaultsOnly, Category="BASE")
	TArray<FPatternBASEEffect> BASEEffectPatterns;

	UPROPERTY(EditDefaultsOnly, Category="BASE")
	FFortBaseWeaponStats DamageStats;

private:
	UFUNCTION()
	void AddNeighborToBaseOnFinishedConstruction(ABuildingSMActor* PlaceOn);

	UFUNCTION()
	void OnBaseCollisionTouched(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnBaseCollisionUnTouched(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnBasePawnDestroyed(AFortPawn* Pawn);

	UFUNCTION()
	void OnBasePawnDied(AFortPawn* Pawn);

	UFUNCTION()
	void OnNeighborDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnNeighborEndPlay(AActor* Actor, const EEndPlayReason::Type EndPlayReason);

};

