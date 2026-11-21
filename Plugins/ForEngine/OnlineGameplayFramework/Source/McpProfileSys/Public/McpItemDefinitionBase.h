// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "McpItemDefinitionBase.generated.h"

UCLASS(Abstract)
class MCPPROFILESYS_API UMcpItemDefinitionBase : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Transient, Category="Item", meta=(DisplayName="Template ID / Persistent Name"))
	FString EditorTemplateId;
#endif

};

