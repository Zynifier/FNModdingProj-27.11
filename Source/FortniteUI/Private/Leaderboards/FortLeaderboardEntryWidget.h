// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortLeaderboardEntryWidget.generated.h"

class UCommonBorder;
class UCommonTextBlock;
class UImage;
class UObject;
class USocialUser;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortLeaderboardEntryWidget : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DisplayPlatformProfile();

protected:
	UPROPERTY(BlueprintReadWrite, Category="Leaderboards")
	TObjectPtr<UObject> LeaderboardEntryObject;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLeaderboardEntryWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Container_PlatformSocialCard;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLeaderboardEntryWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlatformSocialCard;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLeaderboardEntryWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_PlatformSocialCard;

	UPROPERTY(Transient)
	TObjectPtr<USocialUser> QueriedSocialUser;

};

