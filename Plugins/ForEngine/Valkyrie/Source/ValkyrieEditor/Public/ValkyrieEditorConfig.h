// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameFramework/GameUserSettings.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "UObject/SoftObjectPath.h"
#include "ValkyrieEditorConfig.generated.h"

UENUM()
enum class EOnlineRegionSelection : uint8
{
	/** UEFN will detect the best region to use. */
	Auto = 0,
	/** The region preference from the Fortnite client is used. */
	User = 1,
};

UCLASS(Config=EditorPerProjectUserSettings)
class VALKYRIEEDITOR_API UValkyrieEditorConfig : public UDeveloperSettings
{
	GENERATED_BODY()

private:
	UFUNCTION()
	TArray<FString> GetPermissionList() const;

	UPROPERTY(EditAnywhere, Config, Category="General", meta=(DisplayName="Enable Valkyrie"))
	bool bValkyrieMode;

	UPROPERTY(EditAnywhere, Config, Category="General", meta=(DisplayName="Restrictive Valkyrie", EditCondition="bValkyrieMode"))
	bool bValkyrieRestrictiveMode;

	UPROPERTY(Config)
	bool bSaveValkyrieRestrictiveMode;

	UPROPERTY(Config)
	bool bCreateAssetsAsExternallyReferenceable;

	UPROPERTY(Config)
	bool bVerseComponentMode;

	UPROPERTY(EditAnywhere, Config, Category="Projects", meta=(DisplayName="Default Project Name"))
	FString DefaultProjectName;

	UPROPERTY(EditAnywhere, Config, Category="Projects", meta=(DisplayName="Default Project Version"))
	FString DefaultProjectVersionSuffix;

	UPROPERTY(EditAnywhere, Config, Category="Projects", meta=(DisplayName="Use Unreal Revision Control For New Projects"))
	bool bUseUnrealSourceControlForNewProjects;

	UPROPERTY(Config)
	bool bAutoUndoOnFailedCheckout;

	UPROPERTY(Config)
	bool bAutomaticallyCheckoutOnAssetModificationValkyrieOverride;

	UPROPERTY(EditAnywhere, Config, Category="Projects", meta=(DisplayName="Only Show Local Projects"))
	bool bShowOnlyLocalProjects;

	UPROPERTY(EditAnywhere, Config, Category="Projects", meta=(DisplayName="Project Folders"))
	TArray<FDirectoryPath> ProjectSearchPaths;

	UPROPERTY(EditAnywhere, Config, Category="Projects", meta=(DisplayName="Project Template Folders"))
	TArray<FDirectoryPath> UserDefinedProjectTemplateSearchPaths;

	UPROPERTY(EditAnywhere, Config, Category="Referenced Content", meta=(ClampMin="0", ConfigRestartRequired="TRUE", Delta="0.05", DisplayName="Cache Size Limit", ForceUnits="GB", UIMax="20", UIMin="0.5"))
	float ReferencedContentCacheSizeGB;

	UPROPERTY(EditAnywhere, Config, Category="Startup", meta=(DisplayName="Startup With Last Project"))
	bool bStartupWithLastProject;

	UPROPERTY(EditAnywhere, Config, Category="Startup", meta=(DisplayName="Only Show Unseen News On Startup"))
	bool bOnlyShowUnseenNewsOnStartup;

	UPROPERTY(EditAnywhere, Config, Category="Startup", meta=(DisplayName="Auto Login On Startup"))
	bool bLoginOnStartup;

	UPROPERTY(EditAnywhere, Config, Category="Startup", meta=(DisplayName="Preferred Region"))
	EOnlineRegionSelection PreferredRegionSelection;

	UPROPERTY(EditAnywhere, Config, Category="GameClient", meta=(DisplayName="Live Edit Enabled"))
	bool bLiveEditEnabled;

	UPROPERTY(EditAnywhere, Config, Category="GameClient", meta=(DisplayName="Game Resolution"))
	FIntPoint ClientResolution;

	UPROPERTY(EditAnywhere, Config, Category="GameClient", meta=(DisplayName="Game Window Mode"))
	TEnumAsByte<EWindowMode::Type> ClientWindowMode;

	UPROPERTY(EditAnywhere, Config, Category="GameClient", meta=(DisplayName="Test On Local Machine"))
	bool bTestOnLocalMachine;

	UPROPERTY(EditAnywhere, Config, Category="GameClient", meta=(DisplayName="Automatically Launch Client When Testing"))
	bool bAutomaticallyLaunchClientWhenTesting;

	UPROPERTY(EditAnywhere, Config, Category="GameClient", meta=(DisplayName="Additional Command Line Arguments"))
	FString AdditionalCommandLineArguments;

	UPROPERTY(EditAnywhere, Config, Category="LocalLaunch", meta=(DisplayName="Automatically Launch Client And Server From Local Binaries When Testing"))
	bool bLaunchClientAndServerWhenTesting;

	UPROPERTY(EditAnywhere, Config, Category="LocalLaunch", meta=(DisplayName="Which Local Client Binary To Run During Local Testing"))
	FString LocalClientBinaryLocation;

	UPROPERTY(EditAnywhere, Config, Category="LocalLaunch", meta=(DisplayName="Additional Args Used When Running Local Client Binary"))
	FString AdditionalClientArgs;

	UPROPERTY(EditAnywhere, Config, Category="LocalLaunch", meta=(DisplayName="Which Local Server Binary To Run During Local Testing"))
	FString LocalServerBinaryLocation;

	UPROPERTY(EditAnywhere, Config, Category="LocalLaunch", meta=(DisplayName="Additional Args Used When Running Local Server Binary"))
	FString AdditionalServerArgs;

	UPROPERTY(EditAnywhere, Config, Category="AdvancedLaunch", meta=(DisplayName="Launch Second Server"))
	bool bLaunchSecondServer;

	UPROPERTY(EditAnywhere, Config, Category="AdvancedLaunch", meta=(DisplayName="Additional Args Used When Running Second Local Server Binary", EditCondition="bLaunchSecondServer", EditConditionHides))
	FString SecondServerAdditionalServerArgs;

	UPROPERTY(Config)
	FString LastNewsTimestamp;

	UPROPERTY(Config)
	FDateTime LastEulaCheckTimestamp;

	UPROPERTY(Config)
	FString LastLoginSuccessUserId;

	UPROPERTY(Config)
	TSet<FString> AdditionalProjectPaths;

	UPROPERTY(Config)
	TSet<FString> TrustedProjectIds;

	UPROPERTY(Config)
	FString LastProjectFileName;

	UPROPERTY(Config)
	FString LastCreatedProjectLocation;

	UPROPERTY(Config)
	FString LastSelectedTeamId;

	UPROPERTY(Config)
	FString EditorServerProjectsLocation;

	UPROPERTY(EditAnywhere, Config, Category="GameClient", meta=(DisplayName="Auto Launch Game"))
	bool bAutoStartGameOnLaunch;

	UPROPERTY(EditAnywhere, Config, Category="Permissions", meta=(EditCondition="bShowPermissions", EditConditionHides, GetOptions="GetPermissionList", HideEditConditionToggle))
	TSet<FString> EnabledPermissions;

	UPROPERTY(VisibleAnywhere, Transient, Category="Permissions", meta=(EditCondition="bShowPermissions", EditConditionHides, HideEditConditionToggle))
	FString EffectivePermissions;

	UPROPERTY(VisibleAnywhere, Transient, Category="Permissions", meta=(EditCondition="bShowPermissions", EditConditionHides, HideEditConditionToggle))
	FString EntitledPermissions;

	UPROPERTY()
	bool bShowPermissions;

};

