// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortCloudSaveItemDefinition.h"
#include "Items/FortMetadataItem.h"
#include "FortCloudSaveItem.generated.h"

UCLASS(Abstract)
class UFortCloudSaveItem : public UFortMetadataItem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FFortCloudSaveInfo cloud_save_info;

};

