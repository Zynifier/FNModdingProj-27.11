// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Collections/AthenaCollectionListGroupEntry.h"
#include "FortSidebarCollectionListGroupEntry.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarCollectionListGroupEntry : public UAthenaCollectionListGroupEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortSidebarCollectionListGroupEntry")
	int32 MaxNumberOfElements;

	UPROPERTY(EditAnywhere, Category="FortSidebarCollectionListGroupEntry")
	int32 MaxNumberOfElements_Mobile;

};

