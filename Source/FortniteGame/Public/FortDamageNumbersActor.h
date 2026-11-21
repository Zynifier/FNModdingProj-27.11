// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortClientOnlyActor.h"
#include "FortCombatTypes.h"
#include "Items/FortStatCategoryEnum.h"
#include "FortDamageNumbersActor.generated.h"

class AActor;
class APawn;
class UMaterialInstanceDynamic;
class UStaticMesh;
class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EFortDamageNumberType : uint8
{
	None = 0,
	Pawn = 1,
	Building = 2,
	Player = 3,
	Shield = 4,
	Score = 5,
	DBNO = 6,
	Percent = 7,
};

USTRUCT()
struct FFortDamageNumberColorInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Damage Number Color Info")
	FString DisplayText;

	UPROPERTY(EditDefaultsOnly, Category="Damage Number Color Info")
	FLinearColor Color;

	UPROPERTY(EditDefaultsOnly, Category="Damage Number Color Info")
	FLinearColor CriticalColor;

	UPROPERTY(EditDefaultsOnly, Category="Damage Number Color Info")
	FGameplayTagContainer Tags;

};

USTRUCT(BlueprintType)
struct FFortDamageNumberInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage Number Info")
	FVector WorldLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage Number Info")
	FVector HitNormal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage Number Info")
	bool bIsCriticalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage Number Info")
	int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage Number Info")
	EFortDamageNumberType DamageNumberType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage Number Info")
	float VisualDamageScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage Number Info")
	EFortElementalDamageType ElementalDamageType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage Number Info")
	EStatCategory ScoreType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage Number Info")
	bool bAttachScoreNumberToPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="Damage Number Info", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage Number Info")
	TArray<TObjectPtr<UMaterialInstanceDynamic>> MeshMIDs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage Number Info")
	float MeshMIDMoveToCameraValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage Number Info")
	TArray<int32> DamageNumberArray;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage Number Info")
	FGameplayTagContainer DamagedActorTags;

	UPROPERTY()
	TWeakObjectPtr<AActor> DamagedActor;

	UPROPERTY()
	TWeakObjectPtr<APawn> DamageCauser;

};

USTRUCT()
struct FLiveDamageNumberComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> Component;

};

USTRUCT()
struct FPooledDamageNumberComponents
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> Components;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class AFortDamageNumbersActor : public AFortClientOnlyActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Damage Numbers")
	void SetMaterialParameters(UPARAM(ref) FFortDamageNumberInfo& NewDamageNumberInfo, const FTransform& CameraTransform, const FVector& NumberLocation);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Damage Numbers")
	float ComponentLifespan;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers", meta=(ArraySizeEnum="/Script/FortniteGame.EFortElementalDamageType"))
	TObjectPtr<UStaticMesh> MeshesByElement[5];

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	TObjectPtr<UStaticMesh> CritBuildingImpactMesh;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers", meta=(ArraySizeEnum="/Script/FortniteGame.EStatCategory"))
	TObjectPtr<UStaticMesh> MeshesByScoreCategory[3];

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FName PlayerMaterialParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	float PlayerMaterialParameterValue;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FName ColorParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FLinearColor HitPlayerColor;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FLinearColor CriticalHitPlayerColor;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FLinearColor HitEnemyColor;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FLinearColor CriticalHitEnemyColor;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FLinearColor HitBuildingColor;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FLinearColor CriticalHitBuildingColor;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FLinearColor ShieldHitColor;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FLinearColor CriticalHitShieldColor;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers", meta=(TitleProperty="DisplayText"))
	TArray<FFortDamageNumberColorInfo> DamageNumberColorInfos;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FName AnimationLifespanParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FName IsCriticalHitParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	float SpacingPercentageForOnes;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	TArray<FName> PositionParameterNames;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	float DistanceFromCameraBeforeDoublingSize;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	float CriticalHitSizeMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	float FontXSize;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	float FontYSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Damage Numbers")
	FVector WorldLocationOffset;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	float NumberOfNumberRotations;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	TArray<FName> ScaleRotationAngleParameterNames;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	TArray<FName> DurationParameterNames;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	float MaxScoreNumberDistance;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FName MoveToCameraParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Percent Damage")
	TArray<FLinearColor> PercentDamageColors;

	UPROPERTY(EditDefaultsOnly, Category="Percent Damage")
	TArray<int32> PercentDamageThresholds;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	int32 CustomStencilDepthValue;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	float CustomBoundsScale;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	TMap<EFortDamageNumberType, float> OffsetScales;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	TMap<EFortDamageNumberType, FVector2D> OffsetVector2Ds;

	UPROPERTY(EditDefaultsOnly, Category="Damage Numbers")
	FVector2D RandomOffsetVector;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortElementalDamageType"))
	FPooledDamageNumberComponents PooledComponentsByElement[5];

	UPROPERTY(Transient)
	FPooledDamageNumberComponents PooledComponentsCritBuildingImpact;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EStatCategory"))
	FPooledDamageNumberComponents PooledComponentsByScoreCategory[3];

	UPROPERTY(Transient)
	TArray<FLiveDamageNumberComponent> LiveComponents;

	UPROPERTY(EditDefaultsOnly, Category="FortDamageNumbersActor")
	TMap<EFortDamageNumberType, FScalableFloat> OffsetAlongNormalByDamageNumberTypeMap;

	UPROPERTY(EditDefaultsOnly, Category="FortDamageNumbersActor")
	TMap<EFortDamageNumberType, FScalableFloat> VerticalOffsetByDamageNumberTypeMap;

};

