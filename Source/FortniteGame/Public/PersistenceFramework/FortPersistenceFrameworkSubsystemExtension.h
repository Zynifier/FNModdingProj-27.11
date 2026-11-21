// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFramework/PersistenceFrameworkFilteredListContainer.h"
#include "PersistenceFramework/PersistenceFrameworkSubsystemExtension.h"
#include "PersistenceFramework/PersistenceFrameworkSubsystemExtension_SaveControl.h"
#include "FortPersistenceFrameworkSubsystemExtension.generated.h"

class UFortGameInstance;
class UFortPersistenceFrameworkPlayerInfo;
class UFortRegisteredPlayerInfo;

UENUM()
enum class EPersistenceFrameworkPlayerRegistration : uint8
{
	Registered = 0,
	UnRegistered = 1,
};

UCLASS()
class FORTNITEGAME_API UFortPersistenceFrameworkFilteredListContainer_Player : public UPersistenceFrameworkFilteredListContainer
{
	GENERATED_BODY()

};

UCLASS()
class FORTNITEGAME_API UFortPersistenceFrameworkPlayerInfo : public UPersistenceFrameworkFilteredListContainer
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FPersistenceFrameworkSaveControl SaveControl;

};

UCLASS()
class FORTNITEGAME_API UFortPersistenceFrameworkSubsystemExtension : public UPersistenceFrameworkSubsystemExtension
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRegisteredPlayerInfo(UFortRegisteredPlayerInfo* RegisteredPlayerInfo);

	UFUNCTION()
	void OnUnRegisteredPlayerInfo(UFortRegisteredPlayerInfo* RegisteredPlayerInfo);

	UFUNCTION()
	void OnUnRegisterPlayerInfoCompleted(UFortRegisteredPlayerInfo* RegisteredPlayerInfo);

	UPROPERTY()
	TWeakObjectPtr<UFortGameInstance> FortGameInstance;

	UPROPERTY()
	TArray<TWeakObjectPtr<UFortRegisteredPlayerInfo>> NewRegisteredPlayers;

	UPROPERTY()
	TSet<TObjectPtr<UFortPersistenceFrameworkPlayerInfo>> PlayerInfos;

	UPROPERTY()
	TSet<TObjectPtr<UFortPersistenceFrameworkPlayerInfo>> InvalidPlayerInfos;

};

