// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Engine/EngineTypes.h"
#include "Misc/Guid.h"
#include "FortContentEncryptionManager.generated.h"

UENUM()
enum class EFortContentEncryptionAllowedReferences : int32
{
	None = 0,
	SoftOnly = 1,
	Any = 2,
};

UENUM()
enum class EFortContentEncryptionCollectionGrouping : int32
{
	Individual = 0,
	Combined = 1,
	ByCosmeticSet = 2,
};

UENUM()
enum class EFortContentEncryptionGroupType : int32
{
	Root = 0,
	Explicit = 1,
};

UENUM()
enum class EFortEncryptionStatus : uint8
{
	ENCRYPTED = 0,
	RELEASED = 1,
};

USTRUCT()
struct FFortContentEncryptionCollection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="FortContentEncryptionCollection")
	bool bEnabled;

	UPROPERTY(EditAnywhere, Config, Category="FortContentEncryptionCollection")
	FCollectionReference Collection;

	UPROPERTY(EditAnywhere, Config, Category="FortContentEncryptionCollection")
	EFortContentEncryptionCollectionGrouping Grouping;

	UPROPERTY(EditAnywhere, Config, Category="FortContentEncryptionCollection")
	EFortContentEncryptionAllowedReferences AllowedReferences;

	UPROPERTY(EditAnywhere, Config, Category="FortContentEncryptionCollection")
	EFortContentEncryptionGroupType GroupType;

};

USTRUCT()
struct FFortEncryptionKey
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Name;

	UPROPERTY()
	FGuid Guid;

	UPROPERTY()
	TArray<uint8> Bytes;

	UPROPERTY()
	EFortEncryptionStatus Status;

};

USTRUCT()
struct FFortKeyChain
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint32 Hash;

	UPROPERTY()
	TArray<FFortEncryptionKey> Keys;

};

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Fort Content Encryption"))
class UFortContentEncryptionSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Collection Encryption")
	TArray<FFortContentEncryptionCollection> Collections;

	UPROPERTY(EditAnywhere, Config, Category="Game Feature Plugin Encryption")
	TArray<FName> EncryptedGameFeaturePluginNames;

	UPROPERTY(EditAnywhere, Config, Category="Live Keychain Query")
	TArray<FString> BackendURLs;

};

