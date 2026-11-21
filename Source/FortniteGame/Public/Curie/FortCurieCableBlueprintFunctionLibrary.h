// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Curie/FortCurieCableSocketComponent.h"
#include "FortCurieCableBlueprintFunctionLibrary.generated.h"

UCLASS()
class UFortCurieCableBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Cable|Socket", meta=(BlueprintThreadSafe, CompactNodeTitle="==", DisplayName="Equal (FortCurieCableSocketIdentifier)"))
	static bool EqualEqual_FortCurieCableSocketIdentifier(FFortCurieCableSocketIdentifier A, FFortCurieCableSocketIdentifier B);

	UFUNCTION(BlueprintPure, Category="Cable|Socket", meta=(BlueprintThreadSafe, CompactNodeTitle="!=", DisplayName="NotEqual (FortCurieCableSocketIdentifier)"))
	static bool NotEqual_FortCurieCableSocketIdentifier(FFortCurieCableSocketIdentifier A, FFortCurieCableSocketIdentifier B);

};

