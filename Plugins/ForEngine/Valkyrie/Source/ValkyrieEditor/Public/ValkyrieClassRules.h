// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "UObject/TopLevelAssetPath.h"
#include "ValkyrieClassRules.generated.h"

USTRUCT()
struct FValkyrieStructRules
{
	GENERATED_BODY()

};

UCLASS()
class VALKYRIEEDITOR_API UValkyrieClassRulesManager : public UEditorSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<FTopLevelAssetPath, FValkyrieStructRules> RulesByStructPath;

};

