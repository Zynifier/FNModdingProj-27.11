// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortCollectionBookSection.generated.h"

class UFortCollectionBookPage;

UCLASS(MinimalAPI, BlueprintType)
class UFortCollectionBookSection : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FName SectionDataRowName;

	UPROPERTY(Transient)
	TObjectPtr<UFortCollectionBookPage> OwningPage;

};

