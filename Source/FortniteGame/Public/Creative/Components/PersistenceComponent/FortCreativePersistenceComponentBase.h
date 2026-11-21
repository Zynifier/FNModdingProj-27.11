// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ComponentInstanceDataCache.h"
#include "Components/ActorComponent.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Misc/Guid.h"
#include "FortLevelDuplicatableInterface.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortCreativePersistenceComponentBase.generated.h"

class AFortMinigame;
class UFortActorOptionsComponent;
class UFortMinigameLogicComponent;
class UObject;

USTRUCT()
struct FCreativePersistenceComponentBaseInstanceData : public FActorComponentInstanceData
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FGuid PersistenceID;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortCreativePersistenceComponentBase : public UActorComponent, public ILevelSaveSpawnable, public ILevelDuplicatable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Persistence")
	void ClearData(const FUniqueNetIdRepl& PlayerId, const FString& SavePath);

	UFUNCTION(BlueprintCallable, Category="Persistence")
	void GenerateNewPersistenceIDAndResaveActor();

	UFUNCTION(BlueprintPure, Category="Persistence")
	FString GetPersistenceID() const;

	UFUNCTION(BlueprintPure, Category="Persistence")
	void GetPersistencePlayersIds(TArray<FUniqueNetIdRepl>& PersistencePlayers) const;

	UFUNCTION(BlueprintCallable, Category="Persistence")
	void InitializePersistenceComponent(UFortMinigameLogicComponent* InLogicComponent, bool bInUniqueForOwner = true);

	UFUNCTION(BlueprintPure)
	static bool IsPersistenceIDValid(const FString& PersistenceID);

	UFUNCTION()
	bool IsPersistenceRequired();

	UFUNCTION(BlueprintCallable, Category="Persistence")
	void LoadData(const FUniqueNetIdRepl& PlayerId, const FString& SavePath, UObject* OutData);

	UFUNCTION()
	void OnPostDuplicate(bool bDuplicateForPie);

	UFUNCTION(BlueprintCallable, Category="Persistence")
	void SaveData(const UObject* Data, const FUniqueNetIdRepl& PlayerId, const FString& SavePath, bool bIsAutoSave = false);

	UFUNCTION(BlueprintCallable, Category="Persistence")
	void SetAutoSaveEnabled(bool bAutoSaveEnabled);

	UFUNCTION(BlueprintCallable)
	void SetUniqueForOwner(bool bInUniqueForOwner);

	UFUNCTION(BlueprintCallable, Category="Persistence")
	bool TryOverridePersistenceIDAndResaveActor(const FString& NewPersistenceID);

	UFUNCTION(BlueprintCallable)
	void UpdateIsPersistencePosible();

protected:
	UFUNCTION()
	void OnAddedToMinigame(AFortMinigame* FortMinigame);

	UFUNCTION()
	void OnRemovedFromMinigame(AFortMinigame* FortMinigame);

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCreativePersistenceComponentBase")
	bool bConnectedToOptionsComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortMinigame> OwningMinigame;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortActorOptionsComponent> OptionsComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMinigameLogicComponent> LogicComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Persistence", meta=(AllowPrivateAccess="true"))
	FString BasePath;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Persistence", meta=(AllowPrivateAccess="true"))
	FString NonUniquePath;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Persistence", meta=(AllowPrivateAccess="true"))
	FString DevicePath;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Persistence", meta=(AllowPrivateAccess="true"))
	bool bUniqueForOwner;

	UPROPERTY(EditInstanceOnly, SaveGame, Category="FortCreativePersistenceComponentBase")
	FGuid PersistenceID;

	UPROPERTY(SaveGame)
	FString OverridePersistenceID;

};

