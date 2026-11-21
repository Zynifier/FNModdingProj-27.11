// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "UObject/NoExportTypes.h"
#include "FortQuestDefinitionComponent.generated.h"

USTRUCT(BlueprintType, meta=(Hidden))
struct FObjectiveExtensionData
{
	GENERATED_BODY()

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew, MinimalAPI)
class UFortQuestDefinitionComponent : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortQuestDefinitionComponent", meta=(BaseStruct="/Script/FortniteGame.ObjectiveExtensionData", ExcludeBaseStruct))
	TMap<FName, FInstancedStruct> ObjectivesExtensionData;

};

