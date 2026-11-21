// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavPathObserverInterface.h"
#include "AI/Navigation/NavigationTypes.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "AI/Navigation/FortDoorLinkOpenerInterface.h"
#include "AI/Navigation/FortNavPathRendererComponent.h"
#include "Athena/AI/FortAthenaPatrolPath.h"
#include "FortEditorPreviewInterface.h"
#include "LevelSaveSpawnableInterface.h"
#include "AIPatrolPathComponent.generated.h"

class AAIController;
class AActor;
class ABuildingActor;
class AFortAthenaPatrolPoint;
class AFortCreativePatrolPath;
class ANavigationData;
class APawn;
class UAIPatrolPathComponent;
class UAIPatrolPathEditorComponent;
class UNavigationPath;
class UNavigationQueryFilter;
class UNavigationSystemV1;
enum class EFortCreativePatrolPathGroup : uint8;
enum class EPatrollingMode : uint8;

UENUM(BlueprintType)
namespace EAIPatrolPathVersion
{
	enum Type
	{
		InitialVersion = 0,
		TemplateFromQuickBarVersion = 1,
		PatrolPointMovedToUserSettingsVersion = 2,
		// -----<new versions can be added before this line>-------------------------------------------------
// - this needs to be the last line (see note below)

		VersionPlusOne = 3,
		LatestVersion = 2,
	};
}

UENUM()
enum class SegmentPathStatus : uint8
{
	INVALID = 0,
	CALCULATING = 1,
	RECALCULATING_PENDING = 2,
	PATH_FAILED = 3,
	PATH_SUCCESS = 4,
};

USTRUCT()
struct FPatrolPathSegmentDetails
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UNavigationPath> Path;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAIPatrolPathComponent> Start;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAIPatrolPathComponent> End;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UAIPatrolPathComponent : public UActorComponent, public ILevelSaveSpawnable, public INavPathObserverInterface, public IFortNavPathRendererInfoInterface, public IFortDoorLinkOpenerInterface, public IEditorPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void GeneratePathPoints(const EFortCreativePatrolPathGroup PatrolPathGroup, const bool bGenerationCausedByDuplication = false);

	UFUNCTION(BlueprintPure)
	TArray<UAIPatrolPathComponent*> GetLinkedPatrolPoints() const;

	UFUNCTION(BlueprintPure)
	bool GetNextAvailablePatrolPathIndex(int32& NextAvailableIndex) const;

	UFUNCTION(BlueprintImplementableEvent)
	TSubclassOf<UNavigationQueryFilter> GetPatrolFilterOptions();

	UFUNCTION(BlueprintImplementableEvent)
	EPatrollingMode GetPatrollingMode() const;

	UFUNCTION(BlueprintImplementableEvent)
	EFortCreativePatrolPathGroup GetPatrolPathGroup() const;

	UFUNCTION(BlueprintPure)
	int32 GetPatrolPathIndex() const;

	UFUNCTION(BlueprintImplementableEvent)
	int32 GetPatrolPathIndexFromDevice() const;

	UFUNCTION(BlueprintPure)
	UAIPatrolPathComponent* GetPatrolPathPoint(const int32 InPatrolPathIndex, const int32 InPatrolPathPointIndex) const;

	UFUNCTION(BlueprintPure)
	int32 GetPatrolPathPointIndex() const;

	UFUNCTION(BlueprintImplementableEvent)
	int32 GetPatrolPathPointIndexFromDevice() const;

	UFUNCTION(BlueprintPure)
	bool HasValidPatrolPath() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnPathExtremitiesChanged(const bool bIsStart, const bool bIsEnd);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPatrolPathActorAssigned();

	UFUNCTION(BlueprintCallable)
	void PostFinishSpawningActor();

	UFUNCTION(BlueprintCallable)
	bool RemovePoint();

	UFUNCTION(BlueprintCallable)
	void RenderToNextAndPreviousPoint();

	UFUNCTION(BlueprintCallable)
	void RenderToNextPoint();

	UFUNCTION(BlueprintCallable)
	void RequestRenderPath();

	UFUNCTION(BlueprintCallable)
	void SetPatrollingMode(const EPatrollingMode NewMode);

	UFUNCTION(BlueprintCallable)
	void SetPatrolPathEnabled(const bool bIsEnabled);

	UFUNCTION(BlueprintCallable)
	void SetPatrolPathGroup(const EFortCreativePatrolPathGroup PatrolPathGroup);

	UFUNCTION(BlueprintCallable)
	void SetRenderPath(const bool bRenderPath);

	UFUNCTION(BlueprintCallable)
	void UpdateEditorComponent();

protected:
	UFUNCTION(BlueprintPure)
	bool CanNextPointBeReached() const;

	UFUNCTION(BlueprintCallable)
	void NotifyEditorUserOptionChanged(const TArray<FString>& UserOptions);

	UFUNCTION()
	void OnAnyPropertyChanged();

#if WITH_EDITOR
	UFUNCTION()
	void OnEditorOwnerDestroyed(AActor* InActor);
#endif

#if WITH_EDITOR
	UFUNCTION()
	void OnOwnerDuplicated(bool bDuplicatedForPIE);
#endif

	UFUNCTION(BlueprintImplementableEvent)
	void PropagatePatrolPathIndexToDevice(const int32 NewPatrolPathIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void PropagatePatrolPathPointIndexToDevice(const int32 NewPatrolPathPointIndex);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool ShouldRenderPath();

	UPROPERTY(EditDefaultsOnly, Category="Sharing")
	TArray<FString> SharedOptionNames;

	UPROPERTY(EditDefaultsOnly, Category="Navigation")
	TSoftClassPtr<APawn> DefaultAIPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FX")
	TSubclassOf<ABuildingActor> PathRendererClass;

	UPROPERTY(EditDefaultsOnly, Category="Navigation")
	bool bAllowPartialPaths;

	UPROPERTY(EditDefaultsOnly, Category="AIPatrolPathComponent")
	FGameplayTagContainer UnableToPlaceNewDeviceTags;

	UPROPERTY(Transient, DuplicateTransient)
	FNavAgentProperties CachedAIAgentProperties;

	UPROPERTY(Transient, DuplicateTransient)
	TObjectPtr<UNavigationSystemV1> CachedNavSystem;

	UPROPERTY(Transient, DuplicateTransient)
	TObjectPtr<ANavigationData> CachedNavData;

	UPROPERTY(EditDefaultsOnly, Category="Navigation")
	TSubclassOf<UNavigationQueryFilter> CachedFilterClass;

	UPROPERTY(BlueprintAssignable)
	FOnPatrolPointFailedToReach OnPatrolPointFailedToReach;

	UPROPERTY(BlueprintAssignable)
	FOnPatrolPointReached OnPatrolPointReached;

	UPROPERTY(BlueprintAssignable)
	FOnPatrolPathStarted OnPatrolPathStarted;

	UPROPERTY(BlueprintAssignable)
	FOnPatrolPathStopped OnPatrolPathStopped;

private:
	UFUNCTION()
	void PatrolPathStarted(AAIController* Instigator);

	UFUNCTION()
	void PatrolPathStopped(AAIController* Instigator);

	UFUNCTION()
	void PatrolPointFailedToReach(AFortAthenaPatrolPoint* PathPoint, AAIController* Instigator);

	UFUNCTION()
	void PatrolPointReached(AFortAthenaPatrolPoint* PathPoint, AAIController* Instigator);

	UPROPERTY(Transient, DuplicateTransient)
	TArray<TObjectPtr<AActor>> PatrolPath;

	UPROPERTY(Transient, DuplicateTransient)
	FPatrolPathSegmentDetails PathSegmentDetails;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAIPatrolPathComponent> CopiedFrom;

	UPROPERTY(Transient, DuplicateTransient)
	TObjectPtr<AActor> CurrentCloningNode;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAIPatrolPathComponent> CopiedFromCut;

	UPROPERTY(BlueprintReadOnly, Transient, DuplicateTransient, Category="AIPatrolPathComponent", meta=(AllowPrivateAccess))
	TObjectPtr<AFortCreativePatrolPath> PatrolPathActor;

	UPROPERTY(Transient, DuplicateTransient)
	TObjectPtr<AFortAthenaPatrolPoint> PatrolPointActor;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAIPatrolPathComponent>> MultiSelectActorToEnterList;

	UPROPERTY(Transient, DuplicateTransient, Export, meta=(EditInline="true"))
	TObjectPtr<UAIPatrolPathEditorComponent> PatrolPathEditorComponent;

};

