// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortCosmeticItemAdditionalData.generated.h"

UCLASS(Abstract, EditInlineNew, MinimalAPI)
class UFortCosmeticItemAdditionalData : public UObject
{
	GENERATED_BODY()

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DesignerFacingVisuals")
	FString DataTitleString;
#endif

};

