// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Editor/TemplateMapInfo.h"
#include "ValkyrieTemplateMapInfo.generated.h"

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieTemplateMapInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FTemplateMapInfo BaseInfo;

	UPROPERTY(Config)
	FText Description;

};

