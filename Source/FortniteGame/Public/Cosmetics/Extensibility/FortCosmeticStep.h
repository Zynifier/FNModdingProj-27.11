// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Extensibility/FortCosmeticExtensibilityTypes.h"
#include "Cosmetics/Extensibility/FortCosmeticFlowNode.h"
#include "FortCosmeticStep.generated.h"

UCLASS(Abstract, MinimalAPI)
class UFortCosmeticStep : public UFortCosmeticFlowNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCosmeticStep")
	FCosmeticFlowGraphKey FlowGraphKey;

};

