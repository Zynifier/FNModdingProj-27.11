// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Athena/AI/FortAthenaAIRuntimeParametersComponent.h"
#include "FortAthenaAISpawnerDataComponent.generated.h"

class UFortAthenaAISpawnerDataComponent;
class UObject;

UENUM()
enum class EFortAthenaAISpawnerDataComponentTriBool : uint8
{
	Yes = 0,
	//Cant use True/False because it seems to confuse UHT and block compilation

	No = 1,
	DoNotModify = 2,
};

UCLASS(Abstract, EditInlineNew)
class FORTNITEAI_API UFortAthenaAISpawnerDataComponent : public UObject, public IFortAthenaAIRuntimeParametersProvider
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Editor Scripting | AI Spawner Data")
	static UFortAthenaAISpawnerDataComponent* GetAISpawnerDataComponentDefaultObject(UObject* SourceObject);
#endif

};

