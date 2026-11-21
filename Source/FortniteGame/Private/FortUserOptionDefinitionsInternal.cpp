// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortUserOptionDefinitionsInternal.h"

#if WITH_EDITOR
void UUserOptionDefinitionLibrary::FixupLegacyUserOptionPropertyFlags(UBlueprint* Blueprint)
{
}
#endif

#if WITH_EDITOR
void UUserOptionDefinitionLibrary::FixupUserOptionEventNames(UBlueprint* Blueprint, const bool bSkipPropertyRename)
{
}
#endif

#if WITH_EDITOR
void UUserOptionDefinitionLibrary::FixupUserOptionPropertyFlags(UBlueprint* Blueprint)
{
}
#endif

#if WITH_EDITOR
void UUserOptionDefinitionLibrary::MigrateLegacyChannelsForBlueprint(UBlueprint* Blueprint, const FUserOptionMigrateLegacyDataConfig Config)
{
}
#endif

#if WITH_EDITOR
void UUserOptionDefinitionLibrary::MigrateLegacyOptionsForBlueprint(UBlueprint* Blueprint, const TMap<FName, FName> OptionToPropertyNameOverrides, const FUserOptionMigrateLegacyDataConfig Config)
{
}
#endif

#if WITH_EDITOR
void UUserOptionDefinitionLibrary::MigrateLegacyOptionsToBlueprint(UBlueprint* Blueprint, const UPlaylistUserOptions* OptionsAsset, const TMap<FName, FName> OptionToPropertyNameOverrides, const FUserOptionMigrateLegacyDataConfig Config)
{
}
#endif

#if WITH_EDITOR
void UUserOptionDefinitionLibrary::MigrateLegacyOptionToBlueprint(UBlueprint* Blueprint, const UPlaylistUserOptionBase* OptionAsset, const UPlaylistUserOptionsFilter* OptionFilter, const FName OptionToPropertyNameOverride, const FUserOptionMigrateLegacyDataConfig Config)
{
}
#endif
