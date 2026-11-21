// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SharedSettingsSubsystem.generated.h"

class UObject;
class USharedSettingsSubsystem;

USTRUCT()
struct FSharedSettingsData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class USharedSettingsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddOrUpdateCachedSharedSettingsData(UObject* ContextObject);

	UFUNCTION(BlueprintPure)
	bool GetCachedResolverScopesForObject(TArray<FName>& OutResolverScopes, int32& OutPriority, bool& bOutBuildSuccess, const UObject* ContextObject) const;

	UFUNCTION(BlueprintCallable)
	static USharedSettingsSubsystem* GetForObject(const UObject* Object, bool bOnlyGameWorlds = true);

	UFUNCTION(BlueprintCallable)
	bool RemoveCachedSharedSettingsData(UObject* ContextObject);

};

