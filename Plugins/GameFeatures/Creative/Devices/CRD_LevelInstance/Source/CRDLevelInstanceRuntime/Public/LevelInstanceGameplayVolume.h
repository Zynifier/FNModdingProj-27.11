// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Building/FortSpatialGameplayInterface.h"
#include "Building/SpatialGameplay/SpatialGameplayTypes.h"
#include "GameplayVolume.h"
#include "LevelInstanceGameplayVolume.generated.h"

class AActor;
class AController;
class AFortLevelInstanceSaveActor;
class AFortMinigame;
class ALevelInstanceGameplayVolume;
class IFortSpatialGameplayInterface;
class UFortClassTrackerComponent;
class UFortCreativeActorCollection;
class UFortMutatorListComponent;
class UObject;
class UPrimitiveComponent;
enum class EFortMinigameState : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorAddRemoveVolume, AActor*, Actor, TScriptInterface<IFortSpatialGameplayInterface>, Volume);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDisabledStateChanged, bool, bNewDisabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelInstanceActorAddAtLocation, AActor*, Actor, const FVector&, Location);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelInstanceContentCollectionChanged, ALevelInstanceGameplayVolume*, LevelInstanceGameplayVolume, TSoftObjectPtr<UFortCreativeActorCollection>, ContentCollection);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelInstanceGuidChanged, ALevelInstanceGameplayVolume*, LevelInstanceGameplayVolume, FGuid, LevelInstanceGuid);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelInstanceNameChanged, ALevelInstanceGameplayVolume*, LevelInstanceGameplayVolume, FString, LevelInstanceName);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelInstanceResolved, ALevelInstanceGameplayVolume*, LevelInstanceGameplayVolume, bool, bSucceeded);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnLevelInstanceSizeChanged, ALevelInstanceGameplayVolume*, LevelInstanceGameplayVolume, int32, SizeX, int32, SizeY, int32, Height);

UCLASS()
class ALevelInstanceGameplayVolume : public AGameplayVolume, public IFortSpatialGameplayInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	AFortLevelInstanceSaveActor* CreateLevelInstanceSaveActor();

	UFUNCTION(BlueprintPure)
	FString GetLevelInstanceName() const;

	UFUNCTION(BlueprintPure)
	bool IsDisabled() const;

	UFUNCTION(BlueprintPure)
	bool IsInEditMode() const;

	UFUNCTION(BlueprintCallable)
	void SetEditMode(bool bInEditMode);

	UFUNCTION(BlueprintCallable)
	void SetLevelInstanceActorGuid(FGuid InLevelInstanceActorGuid);

	UFUNCTION(BlueprintCallable)
	void SetLevelInstanceContentCollection(TSoftObjectPtr<UFortCreativeActorCollection> ContentCollection);

	UFUNCTION(BlueprintCallable)
	void SetLevelInstanceName(const FString& InName);

	UFUNCTION(BlueprintCallable)
	void SetWantsLevelLoaded(bool bInWantsLevelLoaded);

	UPROPERTY(BlueprintAssignable)
	FOnLevelInstanceResolved OnLevelInstanceResolved;

	UPROPERTY(BlueprintAssignable)
	FOnDisabledStateChanged OnDisabledStateChanged;

	UPROPERTY(BlueprintAssignable)
	FOnLevelInstanceGuidChanged OnLevelInstanceGuidChanged;

	UPROPERTY(BlueprintAssignable)
	FOnLevelInstanceNameChanged OnLevelInstanceNameChanged;

	UPROPERTY(BlueprintAssignable)
	FOnLevelInstanceSizeChanged OnLevelInstanceSizeChanged;

	UPROPERTY(BlueprintAssignable)
	FOnLevelInstanceContentCollectionChanged OnLevelInstanceContentCollectionChanged;

protected:
	UFUNCTION(BlueprintCallable)
	void CheckForOverlappingVolumes();

	UFUNCTION()
	void HandleActorHealthChanged(AActor* Actor, float NewHealth);

	UFUNCTION(BlueprintCallable)
	void InstantiateFromLevelInstanceSaveActor();

	UFUNCTION(BlueprintPure)
	bool IsPreviewActor() const;

	UFUNCTION()
	void LevelInstanceBeingDestroyed();

	UFUNCTION()
	void LevelInstanceContentChanged(const AActor* InstigatorActor);

	UFUNCTION()
	void LevelInstanceContentCollectionChanged(const AActor* InstigatorActor, TSoftObjectPtr<UFortCreativeActorCollection> ContentCollection);

	UFUNCTION()
	void LevelInstanceNameChanged(const FString& Name);

	UFUNCTION()
	void LevelInstanceSizeChanged(const AActor* InstigatorActor);

	UFUNCTION()
	void OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MiniGameState);

	UFUNCTION()
	void OnRep_EditMode();

	UFUNCTION()
	void OnRep_InstanceLoaded();

	UFUNCTION()
	void OnRep_IsDisabled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnVolumeChanged();

	UFUNCTION()
	void RemoveActorWhenDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void RemoveActorWhenEndPlay(AActor* Actor, const EEndPlayReason::Type EndPlayReason);

	UFUNCTION(BlueprintCallable)
	void SetReadyForInstantiation(bool bReady);

	UPROPERTY(Transient, ReplicatedUsing=OnRep_EditMode)
	bool bEditMode;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsDisabled)
	bool bDisabled;

	UPROPERTY(Transient, Replicated)
	ESpatialLoadingState LoadingState;

	UPROPERTY(Transient, Replicated)
	FString LevelInstanceName;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_InstanceLoaded, Category="LevelInstanceGameplayVolume")
	bool bInstanceLoaded;

	UPROPERTY(Transient, Replicated)
	bool bWantsLevelLoaded;

	UPROPERTY(EditAnywhere, Category="LevelInstanceGameplayVolume")
	bool bConvertStructuresToProps;

	UPROPERTY(Transient)
	TObjectPtr<AFortMinigame> CachedMinigame;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="LevelInstanceGameplayVolume", meta=(EditInline="true"))
	TObjectPtr<UFortMutatorListComponent> MutatorListComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="LevelInstanceGameplayVolume", meta=(EditInline="true"))
	TObjectPtr<UFortClassTrackerComponent> ClassFilterComponent;

	UPROPERTY(EditAnywhere, Category="LevelInstanceGameplayVolume")
	TArray<TSubclassOf<UObject>> BlacklistedClasses;

	UPROPERTY(Transient)
	FGuid LevelInstanceSaveActorGuid;

	UPROPERTY(Transient)
	TObjectPtr<AFortLevelInstanceSaveActor> LevelInstanceSaveActor;

};

