// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "Mobile/LayoutProfile/FortMobileHUDLayoutProfileSaveTypes.h"
#include "FortMobileHUDProfile.generated.h"

USTRUCT()
struct FFortMobileHUDProfileIdentifier
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDProfileIdentifier")
	FGameplayTag HUDProfileType;

	UPROPERTY(VisibleAnywhere, Category="FortMobileHUDProfileIdentifier")
	FGuid Guid;

};

USTRUCT()
struct FFortMobileHUDProfileBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDProfileBase")
	FFortMobileHUDProfileIdentifier HUDProfileIdentifier;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDProfileBase")
	FText HUDProfileName;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDProfileBase")
	FGameplayTag HUDProfileBaseType;

};

USTRUCT()
struct FFortMobileCustomHUDProfile : public FFortMobileHUDProfileBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMobileCustomHUDProfile")
	FFortMobileSchemaModificationContainer Modifications;

};

USTRUCT()
struct FFortMobileHUDPreset : public FFortMobileHUDProfileBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDPreset")
	FFortMobileHUDLayoutProfileSave HUDLayoutPreset;

};

USTRUCT()
struct FFortMobileHUDProfileContainer
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDProfileContainer")
	FFortMobileHUDProfileIdentifier ActiveHUDProfileIdentifier;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDProfileContainer", meta=(TitleProperty="HUDProfileTag"))
	TArray<FFortMobileCustomHUDProfile> CustomHUDProfiles;

};

