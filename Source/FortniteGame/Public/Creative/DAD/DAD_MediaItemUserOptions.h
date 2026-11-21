// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Creative/DAD/DAD_CreativeUserOptions.h"
#include "DAD_MediaItemUserOptions.generated.h"

USTRUCT(BlueprintType)
struct FDAD_MediaItemUserOption : public FDAD_BaseCreativeUserOption
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DAD_MediaItemUserOption")
	FString OptionValueName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DAD_MediaItemUserOption", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

};

UCLASS()
class UDAD_MediaItemUserOptions : public UDAD_CreativeUserOptions
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const TArray<FDAD_MediaItemUserOption>& GetMediaOptions() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="DAD_MediaItemUserOptions", meta=(Patchable))
	TArray<FDAD_MediaItemUserOption> MediaItemUserOptionsList;

};

