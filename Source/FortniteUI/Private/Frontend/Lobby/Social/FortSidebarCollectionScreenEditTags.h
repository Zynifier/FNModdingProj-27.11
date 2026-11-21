// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Collections/AthenaCollectionScreenBase.h"
#include "Frontend/Lobby/Social/SocialTagWidget.h"
#include "FortSidebarCollectionScreenEditTags.generated.h"

class UFortCollectionDataSocialTag;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSidebarCollectionScreenEditTags : public UAthenaCollectionScreenBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortSidebarCollectionScreenEditTags")
	ESocialTagCategory SocialTagCategory;

protected:
	UPROPERTY()
	TObjectPtr<UFortCollectionDataSocialTag> SocialTagCollectionData;

};

