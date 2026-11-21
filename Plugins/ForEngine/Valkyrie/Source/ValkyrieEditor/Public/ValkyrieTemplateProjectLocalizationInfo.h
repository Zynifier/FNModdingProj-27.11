// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ValkyrieTemplateProjectLocalizationInfo.generated.h"

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieTemplateProjectLocalizationInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ValkyrieTemplateProjectLocalizationInfo")
	FString ProjectFilePath;

	UPROPERTY(EditAnywhere, Category="ValkyrieTemplateProjectLocalizationInfo")
	FText ProjectTitle;

	UPROPERTY(EditAnywhere, Category="ValkyrieTemplateProjectLocalizationInfo")
	FText ProjectDescription;

};

