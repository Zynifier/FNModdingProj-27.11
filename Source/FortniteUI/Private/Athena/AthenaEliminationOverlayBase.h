// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaEliminationOverlayBase.generated.h"

UCLASS(Abstract)
class UAthenaEliminationOverlayBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaEliminationOverlayBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

