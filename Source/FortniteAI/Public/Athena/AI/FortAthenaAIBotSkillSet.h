// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Athena/AI/FortAthenaAIRuntimeParametersComponent.h"
#include "FortAthenaAIBotSkillSet.generated.h"

UCLASS(Abstract)
class FORTNITEAI_API UFortAthenaAIBotDigestedSkillSet : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

};

UCLASS(Abstract, EditInlineNew, BlueprintType, Blueprintable)
class FORTNITEAI_API UFortAthenaAIBotSkillSet : public UObject, public IFortAthenaAIRuntimeParametersProvider
{
	GENERATED_BODY()

};

