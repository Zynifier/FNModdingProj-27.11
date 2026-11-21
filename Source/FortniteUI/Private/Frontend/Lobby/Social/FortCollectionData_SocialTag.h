// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Collections/FortCollectionData.h"
#include "Frontend/Lobby/Social/SocialTagWidget.h"
#include "FortCollectionData_SocialTag.generated.h"

UCLASS(MinimalAPI, AutoExpandCategories=("SocialTag"))
class UFortCollectionDataEntrySocialTag : public UFortCollectionDataEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SocialTag")
	FText EntryName;

	UPROPERTY()
	ESocialTagCategory TagCategory;

};

UCLASS(MinimalAPI)
class UFortCollectionDataSocialTag : public UFortCollectionData
{
	GENERATED_BODY()

};

