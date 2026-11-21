// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTransientOverrideUtils.generated.h"

USTRUCT()
struct FTransientOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TransientOverride")
	FName ObjectName;

	UPROPERTY(EditAnywhere, Category="TransientOverride")
	FName PropertyName;

	UPROPERTY(EditAnywhere, Category="TransientOverride")
	bool bMarkTransient;

};

