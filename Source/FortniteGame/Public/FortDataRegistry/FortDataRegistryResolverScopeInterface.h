// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDataRegistryResolverScopeInterface.generated.h"

class UObject;

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortDataRegistryResolverScopeInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="DataRegistry")
	bool BuildDataRegistryResolverScope(TArray<FName>& InOutResolverScopes, int32& InOutPriority) const;

	UFUNCTION(BlueprintNativeEvent, Category="DataRegistry")
	const UObject* GetCacheContextOverride() const;

};

