// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaTrackableAIObjectInterface.h"
#include "FortAthenaPatrolPath.generated.h"

class AAIController;
class AActor;
class AFortAthenaPatrolPoint;
class UBillboardComponent;
class UPatrolPathRenderingComponent;

UENUM(BlueprintType)
enum class EPatrollingMode : uint8
{
	BackAndForth = 0,
	Loop = 1,
	StopAtEnd = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPatrolPathActivationStatusChanged, bool, bIsEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPatrolPathStarted, AAIController*, Instigator);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPatrolPathStopped, AAIController*, Instigator);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPatrolPointFailedToReach, AFortAthenaPatrolPoint*, PatrolPathPoint, AAIController*, Instigator);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPatrolPointReached, AFortAthenaPatrolPoint*, PatrolPathPoint, AAIController*, Instigator);

USTRUCT()
struct FPatrolPathLeash
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Leash")
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditAnywhere, Category="Leash", meta=(ClampMin="0.000000"))
	float Width;

	UPROPERTY(EditAnywhere, Category="Leash", meta=(ClampMin="0.000000"))
	float Height;

};

UCLASS(MinimalAPI)
class AFortAthenaPatrolPath : public AActor, public IFortAthenaTrackableAIObjectInterface, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	virtual bool CanBeUsed() const;

	UFUNCTION(BlueprintPure)
	AFortAthenaPatrolPoint* GetPatrolPoint(const int32 Index) const;

	UFUNCTION(BlueprintPure)
	void GetPatrolPoints(TArray<AFortAthenaPatrolPoint*>& OutPatrolPoints) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void PatrolPathStarted(AAIController* AIInstigator) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void PatrolPathStopped(AAIController* AIInstigator) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void PatrolPointFailedToReach(AFortAthenaPatrolPoint* PathPoint, AAIController* AIInstigator) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void PatrolPointReached(AFortAthenaPatrolPoint* PathPoint, AAIController* AIInstigator) const;

	UFUNCTION(BlueprintCallable)
	void SetPatrolPathEnabled(const bool bIsEnabled);

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UFUNCTION()
	void OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PatrolPath")
	EPatrollingMode Mode;

	UPROPERTY(EditAnywhere, Category="PatrolPath")
	TArray<TObjectPtr<AFortAthenaPatrolPoint>> PatrolPoints;

	UPROPERTY(EditAnywhere, Category="PatrolPath")
	bool bUseRandomStartupPatrolPoint;

	UPROPERTY(EditAnywhere, Category="PatrolPath")
	bool bUseRandomStartupDirection;

	UPROPERTY(EditAnywhere, Category="PatrolPath")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, Category="Radial Leash - Override")
	TObjectPtr<AActor> RadialLeashLocationActorOverride;

	UPROPERTY(EditAnywhere, Category="Radial Leash - Override")
	float RadialLeashInnerRadiusOverride;

	UPROPERTY(EditAnywhere, Category="Radial Leash - Override")
	float RadialLeashOuterRadiusOverride;

	UPROPERTY(EditAnywhere, Category="Path Leash")
	TArray<FPatrolPathLeash> PathLeashArray;

	UPROPERTY(EditAnywhere, Category="Water")
	FScalableFloat WaterLevelIndexMax;

	UPROPERTY(EditAnywhere, Category="Water")
	FScalableFloat WaterLevelIndexMin;

	UPROPERTY(BlueprintAssignable)
	FOnPatrolPointFailedToReach OnPatrolPointFailedToReach;

	UPROPERTY(BlueprintAssignable)
	FOnPatrolPointReached OnPatrolPointReached;

	UPROPERTY(BlueprintAssignable)
	FOnPatrolPathStarted OnPatrolPathStarted;

	UPROPERTY(BlueprintAssignable)
	FOnPatrolPathStopped OnPatrolPathStopped;

	UPROPERTY(BlueprintAssignable)
	FOnPatrolPathActivationStatusChanged OnPatrolPathActivationStatusChanged;

private:
	UPROPERTY(EditAnywhere, Category="PatrolPath")
	FScalableFloat MaxConcurrentUsage;

	UPROPERTY(Transient)
	int32 CurrentConcurrentUsage;

	UPROPERTY(EditAnywhere, Category="PatrolPath")
	FScalableFloat MaxLifetimeUsage;

	UPROPERTY(EditAnywhere, Category="PatrolPath")
	float DebugLinkWidthSelected;

	UPROPERTY(EditAnywhere, Category="PatrolPath")
	float DebugLinkWidthNotSelected;

	UPROPERTY(EditAnywhere, Category="PatrolPath")
	FLinearColor DebugNotSelectedColor;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaPatrolPath", meta=(AllowPrivateAccess="true"))
	uint8 bIsPatrolPathEnabled : 1;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPatrolPathRenderingComponent> RenderingComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TArray<TSoftObjectPtr<AFortAthenaPatrolPoint>> PatrolPointsSoftCopy;
#endif

};

UCLASS(HideCategories=("Object", "Mobility", "VirtualTexture", "Trigger"))
class UPatrolPathRenderingComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

};

