// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManager_PersistenceFramework.generated.h"

class UObject;
class UPFWCheatTestSetup;
class UPersistenceFrameworkActionQueue;

UCLASS()
class FORTNITEGAME_API UFortCheatManager_PersistenceFramework : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PersistenceExampleDoCommand(const FString& CommandLine);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PersistenceExampleDoDeInit(const FString& CommandLine);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PersistenceExampleDoInit(const FString& CommandLine);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PersistenceExampleDoSaveAndRestore(const FString& CommandLine);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PersistenceExampleTriggerSaveControl(const FString& CommandLine);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TestPersistenceDeinitSubsystem(const FString& CommandLine) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TestPersistenceLoginAndLogout(const FString& CommandLine);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TestPersistenceName(const FString& CommandLine);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TestPersistenceQuestContainerRestore(const FString& CommandLine);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TestPersistenceQuestContainerRestoreAll(const FString& CommandLine);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TestPersistenceQuestContainerSave(const FString& CommandLine);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TestPersistenceQuestContainerSaveAll(const FString& CommandLine);

protected:
	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> TestActionsQueue;

	UPROPERTY()
	TObjectPtr<UPFWCheatTestSetup> TestClass;

	UPROPERTY()
	TMap<FString, TSubclassOf<UObject>> AvailableCheatClasses;

};

