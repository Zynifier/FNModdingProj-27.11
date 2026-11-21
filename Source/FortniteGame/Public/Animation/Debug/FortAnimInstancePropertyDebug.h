// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortAnimInstancePropertyDebug.generated.h"

UCLASS()
class UFortAnimInstancePropertyDebug : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void AddPropertyFilter(const FString& Filter);

	UFUNCTION(Exec)
	bool RemovePropertyFilter(const FString& Filter);

	UFUNCTION(Exec)
	void ResetPropertyFilters();

	UFUNCTION(Exec)
	void TogglePropertyFilter(const FString& Filter);

};

